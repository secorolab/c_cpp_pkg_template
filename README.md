# C_CPP Template Repository

This repository is a template for C/C++ packages.

## Package structure

``` bash
.
└── c_cpp_pkg_template
    ├── .clang-format
    ├── .clang-tidy
    ├── CMakeLists.txt
    ├── docs
    │   ├── assets
    │   │   └── placeholder
    │   ├── index.md
    │   └── javascripts
    │       └── mathjax.js
    ├── .github
    │   └── workflows
    │       └── mkdocs_ci_gh_pages.yml
    ├── .gitignore
    ├── include
    │   └── PackageName
    │       ├── temp.hpp
    │       └── template.h
    ├── mkdocs.yaml
    ├── PackageName-config.cmake.in
    ├── .pre-commit-config.yaml
    ├── README.md
    ├── src
    │   ├── CMakeLists.txt
    │   ├── example
    │   │   ├── CMakeLists.txt
    │   │   └── temp_ex.c
    │   └── template.c
    └── test
        ├── CMakeLists.txt
        ├── main_test.c
        └── temp_test.c
```

## Setup

### Prerequisites

- CMake
- C/C++ compiler
- check (unit testing framework)
- clang-format
- clang-tidy
- pre-commit

#### Install prerequisites

``` bash
sudo apt-get install check clang-format clang-tidy

pip install pre-commit
```

### Workspace setup

``` bash
mkdir ~/c_cpp_ws && cd ~/c_cpp_ws

mkdir build install src
```

> [!IMPORTANT]
> The workspace directory structure is recommended, but not mandatory.
You can use any directory structure you prefer.

### Package setup

#### Cloning

1. Clone the repository

    ``` bash
    cd ~/c_cpp_ws/src

    git clone git@github.com:secorolab/c_cpp_pkg_template.git
    ```

2. Rename the cloned repository

    ``` bash
    mv c_cpp_pkg_template <PackageName>

    cd <PackageName>
    ```

3. Rename the `PackageName` in the CMakeLists.txt file, header and source files, folder names,
config file, etc.

</details>

or

#### Creating on your own

1. Follow the package structure and create the necessary files and directories
2. Add the necessary content to the files
3. Initialize the git repository

    ``` bash
    git init
    ```

</details>

## Pre-commit setup

1. Make sure the `git` repository is initialized.

2. Run the following command in the `root` directory of the package to install the pre-commit hooks.

    ``` bash
    pre-commit install
    ```

## Build and install

1. Create a build directory for the package

    ``` bash
    cd ~/c_cpp_ws/build

    mkdir PackageName && cd PackageName
    ```

2. Run the following command in the build directory

    ``` bash
    cmake -DCMAKE_INSTALL_PREFIX=../../install ../../src/PackageName -DCMAKE_BUILD_TYPE=Debug \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DENABLE_TESTS=ON
    ```

    - `-DCMAKE_INSTALL_PREFIX=../../install`: Specifies the installation directory
    - `-DCMAKE_BUILD_TYPE=Debug`: Specifies the build type (Debug, Release, RelWithDebInfo, MinSizeRel)
    - `-DCMAKE_EXPORT_COMPILE_COMMANDS=ON`: Generates compile_commands.json file
    - `-DENABLE_TESTS=ON`: Enables the unit tests

3. Build the package

    ``` bash
    make -j $(nproc)
    ```

    - If `ENABLE_TESTS` is set to `ON`, the tests will be built as well.

4. Install the package

    ``` bash
    make install
    ```

> [!IMPORTANT]
> Refer the [best practices](https://github.com/secorolab/.github-private/blob/main/best_practices/c_cpp.md)
for more information.
