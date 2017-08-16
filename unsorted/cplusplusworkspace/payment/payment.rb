input = 0
ranges = [0,0,0,0,0,0]
while input != -1 do
    input = gets.chomp.to_i
    if input == -1
        break
    end
    if 0 <= input and input <= 9999
        ranges[0]+=1
    elsif 10000 <= input and input <= 19999
        ranges[1]+=1
    elsif 20000 <= input and input <= 29999
        ranges[2]+=1
    elsif 30000 <= input and input <= 39999
        ranges[3]+=1
    elsif 40000 <= input and input <= 49999
        ranges[4]+=1
    else
        ranges[5]+=1
    end
end
for i in 0..5
    puts ranges[i]
end
