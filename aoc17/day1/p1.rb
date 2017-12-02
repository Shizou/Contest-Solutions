code = gets.chomp.to_s()
code_len = code.length
ans = 0
for i in 0..code_len
    puts i
    if code[i] == code[(i+1)%code_len] 
        ans += code[i].to_i
    end
end
puts "ans is: " + ans.to_s
