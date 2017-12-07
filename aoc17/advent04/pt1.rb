line = gets.to_s
tot_lines = 0
invalid = 0
while line != ""
    line = line.split(' ')
    words = {}
    tot_lines += 1
    for i in 0...line.size()
        word = line[i]
        if words.has_key?(word) 
            invalid += 1
            break
        end
        words[word]=i
    end
    line = gets.to_s
end
puts tot_lines-invalid
