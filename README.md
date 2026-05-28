# lab06

Laboratory work VI: package generation with CPack.

The project is based on the previous `print` CMake library and adds package generation.

## Build

```sh
cmake -S . -B _build -DBUILD_TESTS=ON
cmake --build _build
cmake --build _build --target test
```

## Package

```sh
cmake -S . -B _build -DCPACK_GENERATOR=TGZ
cmake --build _build --target package
```

You can also run CPack directly:

```sh
cd _build
cpack -G TGZ
cpack -G DEB
```

## Version

The package version is `0.1.0.0`, as required by the lab06 tutorial.

## Files

- `CMakeLists.txt` - CMake build with version variables and CPack hook.
- `CPackConfig.cmake` - CPack configuration.
- `include/print.hpp` - public header.
- `sources/print.cpp` - library implementation.
- `tests/test1.cpp` - simple test.
- `PackageDescription.txt` - package description.
- `CHANGES.md` - changelog.
