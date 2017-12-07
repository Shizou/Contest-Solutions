$RIGHT = 0
$UP = 1
$LEFT = 2
$DOWN = 3

def choose_direction(dir)
    next_step = dir
    if dir == $RIGHT
        next_step = $UP
    elsif dir == $UP
        next_step = $LEFT
    elsif dir == $LEFT
        next_step = $DOWN
    elsif dir == $DOWN
        next_step = $RIGHT
    end
    return next_step
end

# num
n =  gets.to_i
# miscleanous stuff for keeping track of how much to move
# in which direction
cur_steps = [1,1,2,2] # how much to move for right,up,left,down direction
dx = [1,0,-1,0]
dy = [0,1,0,-1]
cur_dir = $RIGHT
cur_num = 1
# assume some arbitrary start point like the origin
x = 0
y = 0
steps_left = cur_steps.at(cur_dir)
step_bump = 2
# puts cur_num.to_s + "(" + x.to_s + "," + y.to_s + ")"
while cur_num != n
    cur_num += 1
    steps_left -= 1
    x += dx[cur_dir]
    y += dy[cur_dir]
    # puts cur_num.to_s + "(" + x.to_s + "," + y.to_s + ")"
    if steps_left == 0
        cur_steps[cur_dir] += step_bump
        cur_dir = choose_direction(cur_dir)
        steps_left = cur_steps[cur_dir] 
    end
end
ans = x.abs + y.abs
puts "(x:" + x.to_s + ", y:" + y.to_s + ")" + " manhatten dist:" +  ans.to_s
