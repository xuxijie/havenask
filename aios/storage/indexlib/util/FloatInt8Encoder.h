/*
 * Copyright 2014-present Alibaba Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <math.h>
#include <memory>

#include "autil/ConstString.h"
#include "autil/mem_pool/Pool.h"

namespace indexlib { namespace util {

class FloatInt8Encoder
{
public:
    FloatInt8Encoder() {}
    ~FloatInt8Encoder() {}

public:
    static autil::StringView Encode(float maxAbs, const float* input, size_t count, autil::mem_pool::Pool* pool)
    {
        if (!input || !pool || count == 0) {
            return autil::StringView::empty_instance();
        }
        size_t bufferSize = GetEncodeBytesLen(count);
        char* buffer = (char*)pool->allocate(bufferSize);
        int32_t compLen = Encode(maxAbs, input, count, buffer, bufferSize);
        assert(compLen == (int32_t)bufferSize);
        return autil::StringView(buffer, compLen);
    }

    static void Encode(float maxAbs, const float input, char* output)
    {
        const float scale_factor = (float)127 / maxAbs;
        int8_t temp = (int8_t)roundf(std::max(-maxAbs, std::min(input, maxAbs)) * scale_factor);
        memcpy(output, &temp, sizeof(int8_t));
    }

    static int32_t Encode(float maxAbs, const float* input, size_t count, char* output, size_t outBufferSize)
    {
        size_t bufferSize = GetEncodeBytesLen(count);
        if (outBufferSize < bufferSize) {
            return -1;
        }

        const float scale_factor = (float)127 / maxAbs;
        int8_t* cursor = (int8_t*)output;
        for (size_t i = 0; i < count; i++) {
            cursor[i] = (int8_t)roundf(std::max(-maxAbs, std::min(input[i], maxAbs)) * scale_factor);
        }
        return (int32_t)bufferSize;
    }

    static int32_t Decode(float maxAbs, const autil::StringView& data, char* output)
    {
        if (data.empty() || data.size() != sizeof(int8_t)) {
            return -1;
        }
        const float scale = maxAbs / 127;
        float temp = scale * ((int8_t*)data.data())[0];
        memcpy(output, &temp, sizeof(float));
        return 1;
    }

    static int32_t Decode(float maxAbs, const autil::StringView& data, char* output, size_t outputLen)
    {
        if (data.empty()) {
            return -1;
        }
        size_t valueCount = GetDecodeCount(data.size());
        if (valueCount * sizeof(float) > outputLen) {
            return -1;
        }

        int8_t* cursor = (int8_t*)data.data();
        const float scale = maxAbs / 127;
        float* outputCursor = (float*)output;
        for (size_t i = 0; i < valueCount; i++) {
            outputCursor[i] = scale * (float)cursor[i];
        }
        return valueCount;
    }

    static size_t GetEncodeBytesLen(size_t count) { return count; }

    static size_t GetDecodeCount(size_t dataLen) { return dataLen; }

private:
    AUTIL_LOG_DECLARE();
};

typedef std::shared_ptr<FloatInt8Encoder> FloatInt8EncoderPtr;
}} // namespace indexlib::util
