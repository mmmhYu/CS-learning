# Lab5-2: 性能优化实验

## 文件说明

- `main.c`：测试驱动、正确性校验、性能测评。
- `convolution.c`：`baseline_convolution` + 学生优化函数 `convolution`。
- `convolution.h`：函数声明与常量。
- `Makefile`：编译、测试、性能评测。


## 快速开始

```bash
make test
```

默认运行测试（512, 1024, 2048, 4096, 8192）各 1 轮。

## 性能评测

```bash
make perf
```

默认运行全量测试各 5 轮，计算几何平均加速比。

## 清理

```bash
make clean
```
清理编译生成的文件。

## 自定义运行

```bash
./lab5 [rounds] [seed]
```

示例（运行 5 轮，随机种子 123）：

```bash
./lab5 5 123
```

