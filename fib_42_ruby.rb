# frozen_string_literal: true

def fib(n)
  return 0 if n.zero?
  return 1 if n == 1

  fib(n - 1) + fib(n - 2)
end

result = fib(42)
puts "fib(42) = #{result}"
