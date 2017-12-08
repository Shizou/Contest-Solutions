def is_numeric(o)
    true if Integer(o) rescue false
end


def init_var(register, key, is_num)
    if not is_num 
        if not register.has_key? key 
            register[key] = 0
        end
    end

end


line = gets.to_s
register = {}
ans = -1/0.0
while line != ""
    info = line.split(' ')
    # X inc/dec Y 
    var = info[0]
    mod = info[1] == "inc" ? 1 : -1
    val = info[2].to_i
    # if X op V
    operand1 = info[4]
    operator = info[5]
    operand2 = info[6]

    is_num_op1 = is_numeric(operand1)
    is_num_op2 = is_numeric(operand2)
   
    init_var(register, var, false)
    init_var(register, operand1, is_num_op1)
    init_var(register, operand2, is_num_op2)

    operand1 = is_num_op1 ? operand1.to_i : register[operand1]
    operand2 = is_num_op2 ? operand2.to_i : register[operand2]
    result = false
    if operator == ">"
        result = operand1 > operand2
    elsif operator == "<"
        result = operand1 < operand2
    elsif operator == "=="
        result = operand1 == operand2
    elsif operator == ">="
        result = operand1 >= operand2
    elsif operator == "<="
        result = operand1 <= operand2
    elsif operator == "!="
        result = operand1 != operand2
    end

    if result
        register[var] += mod*val
    end 
    line = gets.to_s
    max_val = register.values.sort.max
    if max_val > ans
        ans = max_val
    end
end

puts  ans
