# C_CPP Template Repository

This repository is a template for C/C++ packages.

## Setup

### Prerequisites

- CMake
- C/C++ compiler
- check (unit testing framework)
- Doxygen
- clang-format
- clang-tidy
- [pre-commit](https://pre-commit.com/)

#### Install prerequisites

```bash
sudo apt-get install doxygen check clang-format clang-tidy

pip install pre-commit
```

### Workspace setup

```bash
mkdir ~/c_cpp_ws && cd ~/c_cpp_ws

mkdir build install src
```

> [!IMPORTANT]
> The workspace directory structure is recommended, but not mandatory.
You can use any directory structure you prefer.

### Package setup

#### Create from template

1. Click on `Use this template` from the repository toolbar and give it a new name.

2. Clone the `new` repository

    ```bash
    cd ~/c_cpp_ws/src

    git clone <url>
    ```

3. Rename the `PackageName` in the CMakeLists.txt file, header and source files, folder names,
config file, etc.

</details>

or

#### Creating on your own

1. Follow the package structure and create the necessary files and directories
2. Add the necessary content to the files
3. Initialize the git repository

    ```bash
    git init
    ```

</details>

## Pre-commit setup

1. Make sure the `git` repository is initialized.

2. Run the following command in the `root` directory of the package to install the pre-commit hooks.

    ```bash
    pre-commit install
    ```

## Build and install

1. Create a build directory for the package

    ```bash
    cd ~/c_cpp_ws/build

    mkdir PackageName && cd PackageName
    ```

2. Run the following command in the build directory

    ```bash
    cmake -DCMAKE_INSTALL_PREFIX=../../install ../../src/PackageName \
        -DCMAKE_BUILD_TYPE=Debug \
        -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
        -DENABLE_TESTS=ON
    ```

    - `-DCMAKE_INSTALL_PREFIX=../../install`: Specifies the installation directory
    - `-DCMAKE_BUILD_TYPE=Debug`: Specifies the build type (Debug, Release, RelWithDebInfo, MinSizeRel)
    - `-DCMAKE_EXPORT_COMPILE_COMMANDS=ON`: Generates compile_commands.json file
    - `-DENABLE_TESTS=ON`: Enables the unit tests
    - `-DENABLE_DOC=ON`: Enables the documentation generation

3. Build the package

    ```bash
    make -j $(nproc)
    ```

    - If `ENABLE_TESTS` is set to `ON`, the tests will be built as well.

4. Install the package

    ```bash
    make install
    ```

## Configs

### MkDocs

- To generate the documentation, you can use the [MkDocs](https://www.mkdocs.org/) tool.
- The [mkdocs.yaml](mkdocs.yaml) file contains the configuration for the documentation.
- Refer to the Plugins and Reference sections in the [Material for MkDocs documentation](https://squidfunk.github.io/mkdocs-material/reference/)
for more information about the configuration.

### Doxygen

- To generate the documentation, you can use the [Doxygen](https://www.doxygen.nl/index.html) tool.
- The [Doxyfile](Doxyfile.in) file contains the default configuration for the documentation.

> [!IMPORTANT]
> Configure the [mkdocs.yaml](mkdocs.yaml) and [mkdocs_gh_pages_deploy.yml](/github/workflows/mkdocs_gh_pages_deploy.yml)
files accordingly based on whether your project has API documentation or not.

### Pre-commit

- The [pre-commit-config.yaml](.pre-commit-config.yaml) file contains the configuration for the
pre-commit hooks.
- Update the `build` and `install` paths in the `clang-format` and `clang-tidy` hooks, based on your
workspace setup.
- Also, update the `Set up build` and `Configure and build` in the [build_format_lint.yml](.github/workflows/build_format_lint.yml),
if you have a different build setup.

### GitHub Actions

- The [build_format_lint.yml](.github/workflows/build_format_lint.yml) file contains the configuration
to test the package build, and check the code formatting and linting.
- The [mkdocs_gh_pages_deploy.yml](.github/workflows/mkdocs_gh_pages_deploy.yml) file contains the
configuration to deploy the documentation to GitHub Pages.
