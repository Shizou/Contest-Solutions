def solve_depth(g, v, t)
    return -Math.sqrt(2*g*t*v**3 + v**4)/g + v**2/g + t*v
end

def solve_depth2(g, v, t)
    return Math.sqrt(2*g*t*v**3 + v**4)/g + v**2/g + t*v
end

def solve_speed(g, h)
    return Math.sqrt(2*g*h)
end

g = gets.to_f
c = gets.to_f
t = gets.to_f

h1 = solve_depth(g, c, t)
h2 = solve_depth2(g, c, t)

if Math.sqrt(2*h1/g) > t
    v = solve_speed(g, h2)
    puts "#{'%.02f' % h2}"
    puts "#{'%.02f' % v}"
else
    v = solve_speed(g, h1)
    puts "#{'%.02f' % h1}"
    puts "#{'%.02f' % v}"
end
