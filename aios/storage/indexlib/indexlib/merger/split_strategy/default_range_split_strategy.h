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

#include <map>
#include <stdint.h>

#include "indexlib/base/Types.h"
#include "indexlib/index/segment_metrics_updater/segment_metrics_updater.h"
#include "indexlib/index_base/index_meta/segment_merge_info.h"
#include "indexlib/index_base/index_meta/version.h"
#include "indexlib/indexlib.h"
#include "indexlib/merger/merge_plan.h"
#include "indexlib/merger/segment_directory.h"
#include "indexlib/merger/split_strategy/split_segment_strategy.h"
#include "indexlib/misc/common.h"
#include "indexlib/misc/log.h"
#include "indexlib/util/KeyValueMap.h"
#include "indexlib/util/metrics/MetricProvider.h"

namespace indexlib { namespace merger {

class DefaultRangeSplitStrategy : public SplitSegmentStrategy
{
public:
    DefaultRangeSplitStrategy(merger::SegmentDirectoryPtr segDir, config::IndexPartitionSchemaPtr schema,
                              index::OfflineAttributeSegmentReaderContainerPtr attrReaders,
                              const index_base::SegmentMergeInfos& segMergeInfos, const MergePlan& plan,
                              std::map<segmentid_t, index::SegmentMetricsUpdaterPtr> hintDocInfos,
                              const util::MetricProviderPtr& metrics);

    ~DefaultRangeSplitStrategy();

public:
    bool Init(const util::KeyValueMap& parameters) override { return true; }
    segmentindex_t DoProcess(segmentid_t oldSegId, docid_t oldLocalId, int64_t& hintValue) override { return 0; }

private:
    IE_LOG_DECLARE();
};

DEFINE_SHARED_PTR(DefaultRangeSplitStrategy);
}} // namespace indexlib::merger
