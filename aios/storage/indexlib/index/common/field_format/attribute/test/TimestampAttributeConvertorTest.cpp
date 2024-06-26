#include "indexlib/index/common/field_format/attribute/TimestampAttributeConvertor.h"

#include "autil/ConstString.h"
#include "autil/mem_pool/Pool.h"
#include "unittest/unittest.h"

namespace indexlibv2::index {

class TimestampAttributeConvertorTest : public TESTBASE
{
public:
    TimestampAttributeConvertorTest() = default;
    ~TimestampAttributeConvertorTest() = default;
    void setUp() override {}
    void tearDown() override {}

private:
    void TestEncode(const std::string& value, uint64_t expectedValue);
};
TEST_F(TimestampAttributeConvertorTest, TestCaseForSimple)
{
    const uint64_t SECOND_MS = 1000;
    const uint64_t MINUTE_MS = 60 * SECOND_MS;
    const uint64_t HOUR_MS = 60 * MINUTE_MS;

    // 599616000000: 1989-01-01 00:00:00
    // 915148800000: 1999-01-01 00:00:00
    // 946684800000: 2000-01-01 00:00:00
    // 631152000000: 1990-01-01 00:00:00

    TestEncode("1989-01-01 12:00:00", 599616000000 + 12 * HOUR_MS);
    TestEncode("1999-01-01 09:12:11.123", 915148800000 + 9 * HOUR_MS + 12 * MINUTE_MS + 11 * SECOND_MS + 123);
    TestEncode("1970-01-01 00:00:00 -1000", 10 * HOUR_MS);
}

void TimestampAttributeConvertorTest::TestEncode(const std::string& value, uint64_t expectedValue)
{
    TimestampAttributeConvertor convertor(false, "", 0);
    autil::mem_pool::Pool pool;
    autil::StringView ret = convertor.Encode(autil::StringView(value), &pool);
    ASSERT_EQ(8, ret.length());
    uint64_t data = *((uint64_t*)ret.data());
    ASSERT_EQ(expectedValue, data);
}
} // namespace indexlibv2::index
