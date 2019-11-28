; ModuleID = 'IR Generator'
source_filename = "IR Generator"

@0 = private unnamed_addr constant [2 x i8] c"\0A\00"
@1 = private unnamed_addr constant [5 x i8] c"%d%s\00"

define i32 @print_arr([10 x i32]* %a) {
entry:
  %0 = getelementptr [10 x i32], [10 x i32]* %a, i32 0, i32 0
  store i32 1, i32* %0
  %1 = getelementptr [10 x i32], [10 x i32]* %a, i32 0, i32 0
  %2 = load i32, i32* %1, align 16
  ret i32 %2
}

define i32 @main() {
entry:
  %i = alloca i32
  %j = alloca i32
  %a = alloca [10 x i32]
  store i32 12, i32* %i
  %0 = load [10 x i32], [10 x i32]* %a, align 4
  %call = call i32 @print_arr([10 x i32] %0)
  store i32 %call, i32* %j
  %1 = load i32, i32* %j, align 4
  %print = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @1, i32 0, i32 0), i32 %1, i8* getelementptr inbounds ([2 x i8], [2 x i8]* @0, i32 0, i32 0))
  ret i32 0
}

declare i32 @printf(i8*, ...)
