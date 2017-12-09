def calc_score(line)
	stack = []
	trash = false
	sum = 0
    trash_sum = 0
	i = 0
	# puts line.size
	while i != line.size
		# print i
		if line[i] == "!"
			i += 1 
			# print ". ! and we skipping to: " + i.to_s
		elsif not trash
			# print ": dis is NOT trash" 
			if line[i] == "{"
				if stack.empty?
					# print ": starting a new"
					stack << ["{", 1]
				else
					# print ": imbedded group"
					stack <<["{", stack[-1][1]+1]
					# print ": adding" + stack[-1].to_s
				end
			elsif line[i] == "<"
				trash = true
			elsif line[i] == "}"	
				# print ": now we popping" + line[i-1] + " "
				elem = stack.pop
				# print elem
				sum += elem[1]
			end
		elsif trash
			# print ": dis is trash" 
			if line[i] == ">"
				trash = false
            else
                trash_sum += 1
			end
		end
		# print "\n"
		i += 1
	end
	return trash_sum
end

line = gets.to_s.tr(" ", "")
while line != ""
	puts calc_score(line)
	line = gets.to_s.tr(" ", "")
end
