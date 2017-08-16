n = gets.chomp.to_i
arr = []
for i in 0..n-1
    val = gets.chomp.to_f
    arr.push(val)
end
max_val = arr[0]
cnt = 0
for i in 1..n-1
    if arr[i] > max_val
       max_val = arr[i] 
       cnt = 0
    elsif arr[i] == max_val
        cnt+=1
    end
end

for i in 0..n-1
    if arr[i] != max_val
        puts "#{'%.02f' % arr[i]}"
    end
end

for i in 0..cnt
    puts "#{'%.02f' % max_val}"
end
