load('//aios/storage:defs.bzl', 'strict_cc_fast_test', 'strict_cc_library')
strict_cc_library(
    name='KKVVDumpTestHelper',
    deps=[
        '//aios/storage/indexlib/index/kkv/dump:InlineSKeyDumper',
        '//aios/storage/indexlib/index/kkv/dump:KKVValueDumper',
        '//aios/storage/indexlib/index/kkv/dump:NormalSKeyDumper',
        '//aios/storage/indexlib/index/kkv/dump:PKeyDumper',
        '//aios/storage/indexlib/index/kkv/dump:kkv_data_dumper',
        '//aios/unittest_framework'
    ]
)
strict_cc_fast_test(
    name='KKVValueDumperTest',
    srcs=['KKVValueDumperTest.cpp'],
    copts=['-fno-access-control'],
    deps=[
        '//aios/storage/indexlib/index/kkv/dump:KKVValueDumper',
        '//aios/unittest_framework'
    ]
)
strict_cc_fast_test(
    name='NormalSKeyDumperTest',
    srcs=['NormalSKeyDumperTest.cpp'],
    copts=['-fno-access-control'],
    deps=[
        '//aios/storage/indexlib/index/kkv/dump:KKVValueDumper',
        '//aios/storage/indexlib/index/kkv/dump:NormalSKeyDumper',
        '//aios/unittest_framework'
    ]
)
strict_cc_fast_test(
    name='InlineSKeyDumperTest',
    srcs=['InlineSKeyDumperTest.cpp'],
    copts=['-fno-access-control'],
    deps=[
        '//aios/storage/indexlib/index/kkv/common:Trait',
        '//aios/storage/indexlib/index/kkv/dump:InlineSKeyDumper',
        '//aios/unittest_framework'
    ]
)
strict_cc_fast_test(
    name='InlineKKVDataDumperTest',
    srcs=['InlineKKVDataDumperTest.cpp'],
    copts=['-fno-access-control'],
    deps=[
        ':KKVVDumpTestHelper',
        '//aios/storage/indexlib/index/kkv/dump:KKVDocSorterFactory',
        '//aios/storage/indexlib/index/kkv/dump:KKVFileWriterOptionHelper',
        '//aios/storage/indexlib/index/kkv/dump:kkv_data_dumper',
        '//aios/unittest_framework'
    ]
)
strict_cc_fast_test(
    name='NormalKKVDataDumperTest',
    srcs=['NormalKKVDataDumperTest.cpp'],
    copts=['-fno-access-control'],
    deps=[
        ':KKVVDumpTestHelper',
        '//aios/storage/indexlib/index/kkv/dump:KKVDocSorterFactory',
        '//aios/storage/indexlib/index/kkv/dump:KKVFileWriterOptionHelper',
        '//aios/storage/indexlib/index/kkv/dump:kkv_data_dumper',
        '//aios/unittest_framework'
    ]
)
strict_cc_fast_test(
    name='PKeyDumperTest',
    srcs=['PKeyDumperTest.cpp'],
    copts=['-fno-access-control'],
    deps=[
        '//aios/storage/indexlib/index/kkv/dump:PKeyDumper',
        '//aios/unittest_framework'
    ]
)
strict_cc_fast_test(
    name='KKVDocSorterTest',
    srcs=['KKVDocSorterTest.cpp'],
    copts=['-fno-access-control'],
    deps=[
        '//aios/storage/indexlib/index/kkv/dump:NormalKKVDocSorter',
        '//aios/storage/indexlib/index/kkv/dump:SKeyCollectInfoPool',
        '//aios/storage/indexlib/index/kkv/dump:SKeyHashComparator',
        '//aios/storage/indexlib/index/kkv/dump:TruncateKKVDocSorter',
        '//aios/unittest_framework'
    ]
)
strict_cc_fast_test(
    name='KKVDocSorterFactoryTest',
    srcs=['KKVDocSorterFactoryTest.cpp'],
    copts=['-fno-access-control'],
    deps=[
        '//aios/storage/indexlib/index/kkv/dump:KKVDocSorterFactory',
        '//aios/unittest_framework'
    ]
)
strict_cc_fast_test(
    name='KKVIndexDumperTest',
    srcs=['KKVIndexDumperTest.cpp'],
    copts=['-fno-access-control'],
    deps=[
        '//aios/storage/indexlib/document/test:KVDocumentBatchMaker',
        '//aios/storage/indexlib/framework:tablet_schema_loader',
        '//aios/storage/indexlib/index/common/field_format/pack_attribute',
        '//aios/storage/indexlib/index/kkv/building:kkv_mem_indexer',
        '//aios/storage/indexlib/index/kkv/dump:KKVIndexDumper',
        '//aios/storage/indexlib/table/kkv_table:table',
        '//aios/unittest_framework'
    ]
)
