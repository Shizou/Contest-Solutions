def in_bounds(it, arr_size)
    return it >= 0 && it < arr_size
end


val = gets.to_s
jumps = []
while val != ""
    val = val.to_i
    jumps.push(val)
    val = gets.to_s
end
it = 0
cnt = 0
while in_bounds(it, jumps.size)
    if jumps[it] >= 3 
        jumps[it] -= 1
        it += jumps[it] + 1 
    else
        jumps[it] += 1
        it += jumps[it] - 1 
    end
    cnt += 1
end
puts cnt
