load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository", "new_git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def third_party_deps():
    if "glog" not in native.existing_rules():
        git_repository(
            name = "glog",
            remote = "https://github.com/google/glog.git",
            # commit = "41f4bf9cbc3e8995d628b459f6a239df43c2b84a",
            commit = "96a2f23dca4cc7180821ca5f32e526314395d26a",
        )

    if "com_github_gflags_gflags" not in native.existing_rules():
        http_archive(
            name = "com_github_gflags_gflags",
            urls = [
                "https://github.com/gflags/gflags/archive/v2.2.2.tar.gz",
            ],
            sha256 = "34af2f15cf7367513b352bdcd2493ab14ce43692d2dcd9dfc499492966c64dcf",
            strip_prefix = "gflags-2.2.2",
        )

    if "gtest" not in native.existing_rules():
      git_repository(
        name = "gtest",
        remote = "https://github.com/google/googletest.git",
        commit = "2fe3bd994b3189899d93f1d5a881e725e046fdc2",
      )

    # http_archive(
    #     name = "testrunner",
    #     urls = ["https://github.com/testrunner/v1.zip"],
    #     sha256 = "...",
    # )
