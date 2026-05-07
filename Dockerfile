FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    g++ cmake ninja-build \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . .

RUN cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
RUN cmake --build build

CMD ["ctest", "--test-dir", "build", "--output-on-failure"]