def fib(n: Int): Int =
  if n == 0 then return 0
  if n == 1 then return 1

  fib(n - 1) + fib(n - 2)
end fib

@main
def main(args: String*): Unit =
  val result = fib(42)
  println(s"fib(42) = ${result}")
end main
