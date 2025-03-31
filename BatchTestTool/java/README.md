# Java Automated Testing Assistant Tool

## Brief Introduction

This tool assists in automating Java code testing procedures. Before utilization, ensure proper configuration of:

* Functional Java solution environment

* Testing infrastructure (e.g., IDEA project with required third-party dependencies)

## Environmental Requirements

1. **Solution Code**:Contains Java implementations requiring validation

2. **Test Cases**:Includes corresponding `xxxTest` verification modules

3. **Development Environment**:Recommended configuration:

   * IntelliJ IDEA 2022.3+

   * Java SDK 11+

   * Maven/Gradle build systems

4. **Package Declarations**: Mandatory package statements at file headers:

   ```java
   package com.example.module;
   ```

## Instructions

1. **Compilation Verification**: Modify path variables in AutomatedTester.java:

   ```Python
   if __name__ == "__main__":
       # Set target directory (modify to actual path)
       target_dir = "C:/Users/admin/Desktop/java/111/untitled2/Test/to_be_tested" 
       add_package_to_java_files(target_dir)
   ```

   * Execution workflow:

   1. Performs batch compilation

   2. Auto-purges non-compiling files&#x20;

   3. Archives successful builds

2. **Package Initialization**

   Configure target directory in e.py:

   ```Java
   Path rootPath = Paths.get("C:/Users/admin/Desktop/java/111/untitled2/Test/to_be_tested")
                      .toAbsolutePath()
                      .normalize();
   ```

   * This script:

   1. Validates package hierarchy

   2. Generates missing declarations&#x20;

   3. Maintains existing configurations

3. **Access Modifier Adjustment**

   Configure root path in AccessModifierFixer.java:

   ```
    Path rootPath = Paths.get("C:/Users/admin/Desktop/java/111/untitled2/Test/to_be_tested")
                   .toAbsolutePath()
                   .normalize();
   ```

4. **Automated Testing Execution**

   **Phase 1 (OCR Testing)**:Execute autotest1.py to:

   * Perform optical character recognition

   * Complete 94 test cycles&#x20;

   * Restrict user input during execution

   **Phase 2 (JUnit Integration)** Run autotest2.py to:

   * Migrate validated code&#x20;

   * Generate JUnit5 test suites&#x20;

   * Produce coverage reports

5. **Result Analysis**

   After the entire testing is completed

   * A result file containing individual compilation results of solution code (in JSONL format) can be located in the corresponding directory under to_be_tested

   * Successfully compiled code execution outcomes are archived under src/compile_passed&#x20;

   * JUnit5 test reports are generated in standardized XML/HTML formats

## Critical Considerations

**1.Dependency Management**

Verify installations of:

* JUnit 5.9.2

* OpenCV 4.7 (OCR dependencies)

* SQLite JDBC 3.40

**2.Path Configuration**

Essential adjustments:

* Use absolute paths

* Escape backslashes in Windows

* Maintain directory structure consistency

**3.Security Protocols**

* Disable antivirus during OCR operations

* Allocate dedicated testing user account

* Enable read/write permissions recursively

**4.Performance Optimization**

* Allocate ≥4GB JVM heap

* SSD storage recommended

* Disable GUI animations

## Points for Attention

* Ensure that the required third-party libraries (such as GoogleTest, sqlite3, etc.) are installed and configured correctly.

* The path and commands should be adjusted according to your actual environment to ensure smooth compilation and testing of the project.

