from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout

class SpdWrapper(ConanFile):
    name = "spd_wrapper"
    version = "1.0"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"
    requires = (
        "spdlog/1.13.0",
        "gtest/1.14.0" 
    )
    exports_sources = "CMakeLists.txt", "src/*", "include/*", "Test/*"

    
    def layout(self):
        cmake_layout(self)
        
    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        from conan.tools.files import copy  
        import os
        
        copy(self, "*.hpp", dst=os.path.join(self.package_folder, "include"), src=os.path.join(self.source_folder, "include"))
        
        copy(self, "*.a", dst=os.path.join(self.package_folder, "lib"), src=self.build_folder, keep_path=False)       # Static lib (Unix)
        copy(self, "*.lib", dst=os.path.join(self.package_folder, "lib"), src=self.build_folder, keep_path=False)     # Static lib (Windows)
        copy(self, "*.dylib", dst=os.path.join(self.package_folder, "lib"), src=self.build_folder, keep_path=False)   # Dynamic (macOS)
        copy(self, "*.so", dst=os.path.join(self.package_folder, "lib"), src=self.build_folder, keep_path=False)      # Dynamic (Linux)
        copy(self, "*.dll", dst=os.path.join(self.package_folder, "bin"), src=self.build_folder, keep_path=False)     # Dynamic (Windows)

    def package_info(self):
        self.cpp_info.libs = ["spd_wrapper"]
