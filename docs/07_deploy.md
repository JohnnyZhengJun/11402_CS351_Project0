# 07: Deployment & CI Strategy

## 1. Deployment Architecture

The Two Sum Bootcamp does not deploy to a traditional web server or application host. Instead, its "production environment" is the **Continuous Integration (CI) Pipeline**. The software is considered successfully deployed when it compiles and passes all automated tests in a pristine, headless cloud environment.


## 2. Infrastructure as Code (IaC)
The deployment environment is codified in `.github/workflows/ci.yml`. This ensures that the testing environment is ephemeral, reproducible, and version-controlled.


### 2.1. The Runner Environment
* **Platform:** GitHub Actions
* **OS:** `ubuntu-latest`

* **Dependencies Installed at Runtime:** `g++`, `cmake`, `ninja-build`

### 2.2. Pipeline Stages
The CI pipeline executes deterministically in the following stages upon every push or pull request to the `main` branch:
1. **Checkout:** Clones the repository into the runner workspace.
2. **Setup:** Installs system-level C++ build tools via `apt-get`.
3. **Configure:** Generates the Ninja build files forcing the C++20 standard and Release optimizations.

4. **Build:** Compiles the `twosum_lib`, `twosum_app`, and `two_sum_tests` binaries.
5. **Test:** Invokes `ctest` to parse `test_cases.txt` and validate algorithmic parity.


## 3. Local "Dry Run" Deployment (Docker)
Before pushing code to trigger the CI pipeline, developers must simulate the deployment locally to prevent pipeline failures.

**Execution Protocol:**
```bash
# 1. Build the isolated Ubuntu image
docker build -t twosum-bootcamp .

# 2. Execute the containerized test suite
docker run --rm twosum-bootcamp