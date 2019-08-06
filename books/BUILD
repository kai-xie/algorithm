package(default_visibility = ["//visibility:public"])

cc_library(
    name = "utils",
    srcs = glob(["utils/*.cc"]),
    hdrs = glob(["utils/*.h"]),
    # visibility = ["//books:__pkg__"],
    deps = [
        "@glog",
    ],
    strip_include_prefix = "//books",
)

cc_library(
    name = "heap_sort",
    srcs = ["ch06/heap_sort.cc"],
    hdrs = ["ch06/heap_sort.h"],
    deps = [
        ":utils",
        "@glog",
    ],
    strip_include_prefix = "//books/ch06",
)

cc_test(
    name = "heap_sort_test",
    srcs = ["ch06/heap_sort_test.cc"],
    deps = [
        # "//books:heap_sort",
        ":heap_sort",
        "//tests:sorting_test_base",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "quick_sort",
    srcs = ["ch07/quick_sort.cc"],
    hdrs = ["ch07/quick_sort.h"],
    deps = [
        ":utils",
        "@glog",
    ],
    strip_include_prefix = "//books/ch07",
)

cc_test(
    name = "quick_sort_test",
    srcs = ["ch07/quick_sort_test.cc"],
    deps = [
        ":quick_sort",
        "//tests:sorting_test_base",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)


cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        ":heap_sort",
        ":quick_sort",
        ":utils",
        "@glog",
    ],
)
