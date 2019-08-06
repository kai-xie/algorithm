package(default_visibility = ["//visibility:public"])

cc_library(
    name = "utils",
    srcs = glob(["utils/*.cc"]),
    hdrs = glob(["utils/*.h"]),
    #   srcs = glob(["*.cc"]),
    #   hdrs = glob(["*.h"]),
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
        # "//utils:utils",
        "@glog",
    ],
    strip_include_prefix = "//books",
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    # copts = [],
    deps = [
        ":heap_sort",
        # "//utils:utils",
        ":utils",
        "@glog",
    ],
)
