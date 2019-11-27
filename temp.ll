; ModuleID = 'IR Generator'
source_filename = "IR Generator"

define i32 @main() {
entry:
  %a = alloca i32
  %i = alloca i32
  store i32 1, i32* %a
  store i32 1, i32* %i
  %0 = load i32, i32* %a, align 4
  %1 = load i32, i32* %i, align 4
  %sum = add nsw i32 %0, %1
  store i32 %sum, i32* %a
  ret i32 0
}
