# frozen_string_literal: true

TIME_FORMAT = <<~FORMAT
  Execution time:
    Real:  %E
    User:  %U
    Sys:   %S
    CPU:   %P

  Memory:
    Max RSS: %M KB
    Avg Mem: %K KB

  I/O:
    Inputs:  %I
    Outputs: %O

  Page faults:
    Major:   %F
    Minor:   %R

  Context switches:
    Involuntary: %c
    Voluntary:   %w
FORMAT

# Rakefile for building and timing Fibonacci implementations in multiple languages
#
# Usage:
#   rake build:all        # Build all compiled implementations
#   rake time:all         # Time all implementations
#   rake build:c          # Build C implementation
#   rake time:c           # Time C implementation

# ========================================
# File Rules - Build targets (alphabetical)
# ========================================

desc 'Build C implementation with optimization'
file 'fib_42_c' => 'fib_42_c.c' do
  sh 'gcc fib_42_c.c -o fib_42_c -O3'
end

desc 'Build Crystal implementation in release mode'
file 'fib_42_crystal' => 'fib_42_crystal.cr' do
  sh 'crystal build fib_42_crystal.cr -o fib_42_crystal --release'
end

desc 'Build Java implementation'
file 'fib_42_java.class' => 'fib_42_java.java' do
  sh 'javac fib_42_java.java'
end

desc 'Build Rust implementation with optimization'
file 'fib_42_rust' => 'fib_42_rust.rs' do
  sh 'rustc fib_42_rust.rs -o fib_42_rust -O'
end

desc 'Build Scala implementation with scala-cli'
file 'fib_42_scala.jar' => 'fib_42_scala.scala' do
  sh 'scala-cli --power package fib_42_scala.scala -o fib_42_scala.jar'
end

# ========================================
# Build Tasks (alphabetical)
# ========================================

namespace :build do
  desc 'Build C implementation'
  task c: %i[fib_42_c]

  desc 'Build Crystal implementation'
  task crystal: %i[fib_42_crystal]

  desc 'Build Java implementation'
  task java: %i[fib_42_java.class]

  desc 'Build Rust implementation'
  task rust: %i[fib_42_rust]

  desc 'Build Scala implementation'
  task scala: %i[fib_42_scala.jar]

  desc 'Build all compiled implementations (C, Crystal, Java, Rust, Scala)'
  task all: %i[c crystal java rust scala]
end

# ========================================
# Time Tasks (alphabetical)
# ========================================

namespace :time do
  desc 'Time C implementation'
  task c: %i[fib_42_c] do
    puts '===== start C ====='
    sh "/usr/bin/time -f \"#{TIME_FORMAT}\" ./fib_42_c", verbose: false
    puts '===== end C ====='
  end

  desc 'Time Crystal implementation'
  task crystal: %i[fib_42_crystal] do
    puts '===== start Crystal ====='
    sh "/usr/bin/time -f \"#{TIME_FORMAT}\" ./fib_42_crystal", verbose: false
    puts '===== end Crystal ====='
  end

  desc 'Time Java implementation'
  task java: %i[fib_42_java.class] do
    puts '===== start Java ====='
    sh "/usr/bin/time -f \"#{TIME_FORMAT}\" java fib_42_java", verbose: false
    puts '===== end Java ====='
  end

  desc 'Time JavaScript implementation using Bun'
  task javascript: 'fib_42_javascript.js' do
    puts '===== start JavaScript ====='
    sh "/usr/bin/time -f \"#{TIME_FORMAT}\" bun run fib_42_javascript.js", verbose: false
    puts '===== end JavaScript ====='
  end

  desc 'Time Ruby implementation'
  task ruby: 'fib_42_ruby.rb' do
    puts '===== start Ruby ====='
    sh "/usr/bin/time -f \"#{TIME_FORMAT}\" ruby fib_42_ruby.rb", verbose: false
    puts '===== end Ruby ====='
  end

  desc 'Time Rust implementation'
  task rust: %i[fib_42_rust] do
    puts '===== start Rust ====='
    sh "/usr/bin/time -f \"#{TIME_FORMAT}\" ./fib_42_rust", verbose: false
    puts '===== end Rust ====='
  end

  desc 'Time Scala implementation'
  task scala: %i[fib_42_scala.jar] do
    puts '===== start Scala ====='
    sh "/usr/bin/time -f \"#{TIME_FORMAT}\" java -jar fib_42_scala.jar", verbose: false
    puts '===== end Scala ====='
  end

  desc 'Time all implementations'
  task all: %i[c crystal java javascript ruby rust scala]
end

# ========================================
# Clean Tasks
# ========================================

namespace :clean do
  desc 'Remove compiled artifacts'
  task :all do
    rm_f %w[fib_42_c fib_42_crystal fib_42_java.class fib_42_rust fib_42_scala.jar]
  end
end

# Default task
desc 'Display available tasks'
task :default do
  sh 'rake -T'
end
