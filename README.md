# C_CPP Template Repository

This repository is a template for C/C++ projects.

## Project structure

``` bash
.
├── .clang-format
├── .clang-tidy
├── CMakeLists.txt
├── include
│   └── ProjectName
│       └── template.h
├── .pre-commit-config.yaml
├── ProjectName-config.cmake.in
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
> The workspace directory structure is recommended, but not mandatory. You can use any directory structure you prefer.

### Package setup

<details>
<summary>Cloning</summary>
<br>

1. Clone the repository

    ``` bash
    cd ~/c_cpp_ws/src

    git clone git@github.com:secorolab/c_cpp_project_template.git
    ```

2. Rename the cloned repository

    ``` bash
    mv c_cpp_project_template ProjectName

    cd ProjectName
    ```

3. Rename the project name in the CMakeLists.txt file in the root directory.

4. Rename the project name in the ProjectName-config.cmake.in file

5. Rename the project name in the include/ProjectName directory

6. Rename the project name in the `.c` and `.h` files where necessary

</details>

or 

<details>
<summary>Creating on your own</summary>
<br>

1. Follow the project structure and create the necessary files and directories
2. Add the necessary content to the files
3. Initialize the git repository

    ``` bash
    git init
    ```

</details>

## Pre-commit setup

1. Make sure the `git` repository is initialized.

2. Run the following command in the root directory of the project.

    ``` bash
    pre-commit install
    ```

## Build

1. Create a build directory for the package

    ``` bash
    cd ~/c_cpp_ws/build

    mkdir ProjectName && cd ProjectName
    ```

2. Run the following command in the build directory

    ``` bash
    cmake -DCMAKE_INSTALL_PREFIX=../../install ../../src/ProjectName -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DENABLE_TESTS=ON
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

## Commit

1. Add the necessary files to the staging area

    ``` bash
    git add .
    ```

2. Commit the changes

    ``` bash
    git commit -m "Initial commit"
    ```

    - The following pre-commit hooks will be executed:
        - clang-format
        - clang-tidy
    - If there are any errors, fix them and commit again.
    - To run the pre-commit hooks manually, run the following command:

        ``` bash
        pre-commit run --all-files
        ```

3. Push the changes to the remote repository

