# Fibonacci 42

多种编程语言实现的斐波那契数列计算（计算 fib(42)），用于性能比较。

## 支持的编程语言

- **C** - 编译型语言
- **Crystal** - 编译型语言，Ruby 语法风格
- **Java** - JVM 语言
- **JavaScript** - 使用 Bun 运行时
- **Ruby** - 解释型语言
- **Rust** - 编译型系统语言
- **Scala** - JVM 函数式语言

## 快速开始

### 构建所有编译型实现

```bash
rake build:all
```

### 运行所有性能测试

```bash
rake time:all
```

## 单独构建和测试

| 语言 | 构建命令 | 测试命令 |
|------|---------|---------|
| C | `rake build:c` | `rake time:c` |
| Crystal | `rake build:crystal` | `rake time:crystal` |
| Java | `rake build:java` | `rake time:java` |
| JavaScript | - | `rake time:javascript` |
| Ruby | - | `rake time:ruby` |
| Rust | `rake build:rust` | `rake time:rust` |
| Scala | `rake build:scala` | `rake time:scala` |

## 清理编译产物

```bash
rake clean:all
```

## 查看所有可用任务

```bash
rake -T
```

## 项目结构

```
.
├── Rakefile                      # 构建和测试脚本
├── fib_42_c.c                    # C 实现
├── fib_42_crystal.cr             # Crystal 实现
├── fib_42_java.java              # Java 实现
├── fib_42_javascript.js          # JavaScript 实现
├── fib_42_ruby.rb                # Ruby 实现
├── fib_42_rust.rs                # Rust 实现
└── fib_42_scala.scala            # Scala 实现
```

## 编译优化

所有编译型语言均使用各自的最高优化级别和静态链接以确保公平对比：

- **C**: `gcc -O3 -static -flto`（最高优化级别 + 静态链接 + 链接时优化）
- **Crystal**: `crystal build --release --static`（最高优化级别 + 静态链接，等同于 `-O3 --single-module`）
  > 注意：Crystal 不支持传统 LTO，但 `--release` 模式使用 `--single-module` 将所有代码编译为单个 LLVM 模块，提供跨模块优化效果
- **Rust**: `rustc -C opt-level=3 -C lto=fat -C prefer-dynamic=no`（最高优化级别 + 链接时优化 + 静态链接）

所有实现都使用 `-O3` 级别的优化和静态链接。C 和 Rust 支持 LTO（链接时优化），Crystal 使用 `--single-module` 机制实现类似效果。

## 性能指标

计时任务会收集以下性能指标：

- **执行时间**: 实际时间、用户时间、系统时间、CPU 使用率
- **内存使用**: 最大 RSS、平均内存
- **I/O**: 输入/输出操作数
- **页面错误**: 主页面错误、次页面错误
- **上下文切换**: 强制切换、自愿切换

## 测试结果

测试环境：Linux x86_64，计算 fib(42) = 267914296

### 执行时间对比

| 排名 | 语言 | 执行时间 | 相对速度 |
|:----:|------|:--------:|:--------:|
| 🥇 | **C** | 0.30s | 1.0x (基准) |
| 🥈 | **Rust** | 0.45s | 1.5x |
| 🥉 | **Java** | 0.75s | 2.5x |
| 4 | **Crystal** | 0.83s | 2.8x |
| 5 | **Scala** | 0.87s | 2.9x |
| 6 | **JavaScript** | 1.30s | 4.3x |
| 7 | **Ruby** | 22.33s | 74.4x |

### 内存使用对比

| 排名 | 语言 | 最大内存 | 内存占用 |
|:----:|------|:--------:|:--------:|
| 🥇 | **C** | 684 KB | 极低 |
| 🥈 | **Rust** | 1,896 KB | 极低 |
| 🥉 | **Crystal** | 2,016 KB | 低 |
| 4 | **Ruby** | 15,584 KB | 中等 |
| 5 | **JavaScript** | 39,508 KB | 较高 |
| 6 | **Java** | 40,808 KB | 较高 |
| 7 | **Scala** | 67,436 KB | 高 |

### 完整性能数据

| 语言 | 执行时间 | 内存使用 | 页面错误 | 上下文切换 |
|------|:--------:|:--------:|:--------:|:----------:|
| C | 0.30s | 684 KB | 53 | 3 |
| Rust | 0.45s | 1,896 KB | 98 | 36 |
| Crystal | 0.83s | 2,016 KB | 254 | 15 |
| Java | 0.75s | 40,808 KB | 5,106 | 152 |
| Scala | 0.87s | 67,436 KB | 11,284 | 1,909 |
| JavaScript | 1.30s | 39,508 KB | 2,602 | 133 |
| Ruby | 22.33s | 15,584 KB | 2,148 | 1,179 |

## 总结与评价

### 🏆 性能冠军

**C 语言**表现最为出色：
- 执行速度最快（0.30秒）
- 内存占用最低（684 KB）
- 系统资源消耗最少

**Rust**紧随其后：
- 速度仅次于 C（0.45秒）
- 内存效率极高（1.9 MB）
- 提供内存安全保障的同时保持高性能

### 📊 分类对比

**编译型语言（C、Rust、Crystal）**：
- 执行速度极快（0.30s - 0.83s）
- 内存占用低（684 KB - 2 MB）
- 适合对性能要求高的场景

**JVM 语言（Java、Scala）**：
- 执行速度中等（0.75s - 0.87s）
- JVM 启动开销较大，内存占用高（41 MB - 67 MB）
- 页面错误和上下文切换频繁

**解释型/运行时语言（JavaScript、Ruby）**：
- JavaScript 使用 Bun 运行时表现尚可（1.30s）
- **Ruby 性能明显落后**（22.33秒，比其他语言慢 25-74 倍）
- 适合快速原型开发，不适合计算密集型任务

### 💡 结论

1. **追求极致性能**：选择 C 或 Rust
2. **平衡性能与开发效率**：选择 Crystal（接近 C 的性能，Ruby 的语法）
3. **企业级应用**：JVM 语言（Java/Scala）虽然启动慢，但运行性能可接受
4. **避免使用**：Ruby 不适合递归计算密集型任务

> **注意**：所有实现都使用了相同的递归算法。Ruby 的缓慢主要源于其解释执行特性和动态类型系统的开销。
