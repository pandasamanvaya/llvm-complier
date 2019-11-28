; ModuleID = 'IR Generator'
source_filename = "IR Generator"

@0 = private unnamed_addr constant [24 x i8] c"Pythagorean triplets :-\00"
@1 = private unnamed_addr constant [2 x i8] c"\0A\00"
@2 = private unnamed_addr constant [5 x i8] c"%s%s\00"
@3 = private unnamed_addr constant [2 x i8] c" \00"
@4 = private unnamed_addr constant [2 x i8] c" \00"
@5 = private unnamed_addr constant [2 x i8] c"\0A\00"
@6 = private unnamed_addr constant [13 x i8] c"%d%s%d%s%d%s\00"
@7 = private unnamed_addr constant [2 x i8] c"\0A\00"
@8 = private unnamed_addr constant [5 x i8] c"%d%s\00"

define i32 @main() {
entry:
  %x = alloca i32
  %y = alloca i32
  %count = alloca i32
  %n = alloca i32
  store i32 0, i32* %count
  store i32 10, i32* %n
  %print = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @2, i32 0, i32 0), i8* getelementptr inbounds ([24 x i8], [24 x i8]* @0, i32 0, i32 0), i8* getelementptr inbounds ([2 x i8], [2 x i8]* @1, i32 0, i32 0))
  store i32 2, i32* %x
  %0 = load i32, i32* %x, align 4
  %1 = load i32, i32* %n, align 4
  %le = icmp sle i32 %0, %1
  br i1 %le, label %for, label %afterfor

for:                                              ; preds = %afterfor2, %entry
  store i32 1, i32* %y
  %2 = load i32, i32* %y, align 4
  %3 = load i32, i32* %x, align 4
  %lt = icmp slt i32 %2, %3
  br i1 %lt, label %for1, label %afterfor2

afterfor:                                         ; preds = %afterfor2, %entry
  %4 = load i32, i32* %count, align 4
  %print14 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @8, i32 0, i32 0), i32 %4, i8* getelementptr inbounds ([2 x i8], [2 x i8]* @7, i32 0, i32 0))
  ret i32 0

for1:                                             ; preds = %for1, %for
  %5 = load i32, i32* %x, align 4
  %6 = load i32, i32* %x, align 4
  %mul = mul nsw i32 %5, %6
  %7 = load i32, i32* %y, align 4
  %8 = load i32, i32* %y, align 4
  %mul3 = mul nsw i32 %7, %8
  %diff = sub nsw i32 %mul, %mul3
  %9 = load i32, i32* %x, align 4
  %mul4 = mul nsw i32 2, %9
  %10 = load i32, i32* %y, align 4
  %mul5 = mul nsw i32 %mul4, %10
  %11 = load i32, i32* %x, align 4
  %12 = load i32, i32* %x, align 4
  %mul6 = mul nsw i32 %11, %12
  %13 = load i32, i32* %y, align 4
  %14 = load i32, i32* %y, align 4
  %mul7 = mul nsw i32 %13, %14
  %sum = add i32 %mul6, %mul7
  %print8 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @6, i32 0, i32 0), i32 %diff, i8* getelementptr inbounds ([2 x i8], [2 x i8]* @3, i32 0, i32 0), i32 %mul5, i8* getelementptr inbounds ([2 x i8], [2 x i8]* @4, i32 0, i32 0), i32 %sum, i8* getelementptr inbounds ([2 x i8], [2 x i8]* @5, i32 0, i32 0))
  %15 = load i32, i32* %count, align 4
  %sum9 = add i32 %15, 1
  store i32 %sum9, i32* %count
  %16 = load i32, i32* %y, align 4
  %sum10 = add i32 %16, 1
  store i32 %sum10, i32* %y
  %17 = load i32, i32* %y, align 4
  %18 = load i32, i32* %x, align 4
  %lt11 = icmp slt i32 %17, %18
  br i1 %lt11, label %for1, label %afterfor2

afterfor2:                                        ; preds = %for1, %for
  %19 = load i32, i32* %x, align 4
  %sum12 = add i32 %19, 1
  store i32 %sum12, i32* %x
  %20 = load i32, i32* %x, align 4
  %21 = load i32, i32* %n, align 4
  %le13 = icmp sle i32 %20, %21
  br i1 %le13, label %for, label %afterfor
}

declare i32 @printf(i8*, ...)
