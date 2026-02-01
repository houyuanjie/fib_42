fn fib(n: i32) -> i32 {
    if n == 0 {
        return 0;
    }
    if n == 1 {
        return 1;
    }

    fib(n - 1) + fib(n - 2)
}

fn main() {
    let result = fib(42);
    println!("fib(42) = {}", result);
}
