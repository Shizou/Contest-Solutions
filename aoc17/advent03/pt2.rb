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

def within_range(x,y)
    return x >= 0 && y >= 0 && x < 5000 && y < 5000
end

# num
n =  gets.to_i
# miscleanous stuff for keeping track of how much to move
# in which direction
grid = Array.new(5000){Array.new(5000)}
cur_steps = [1,1,2,2] # how much to move for right,up,left,down direction
dx = [1,0,-1,0]
dy = [0,1,0,-1]
dx2 = [0, 1, 1, 1, 0, -1, -1, -1]
dy2 = [1, 1, 0, -1, -1, -1, 0, 1]
cur_dir = $RIGHT
cur_num = 1
# assume some arbitrary start point like the origin
x = 1000
y = 1000
steps_left = cur_steps.at(cur_dir)
step_bump = 2
grid[x][y] = 1
# puts cur_num.to_s + "(" + x.to_s + "," + y.to_s + ")"
while true 
    cur_num += 1
    steps_left -= 1
    x += dx[cur_dir]
    y += dy[cur_dir]
    cur_val = 0
    for d in 0...8
        cx = x + dx2[d]
        cy = y + dy2[d]
        if within_range(cx, cy) && grid[cx][cy] != nil
            cur_val += grid[cx][cy]
        end
    end
    grid[x][y] = cur_val
    if cur_val > n
        puts cur_val
        exit(0)
    end
    # puts cur_num.to_s + "(" + x.to_s + "," + y.to_s + ")"
    if steps_left == 0
        cur_steps[cur_dir] += step_bump
        cur_dir = choose_direction(cur_dir)
        steps_left = cur_steps[cur_dir] 
    end
end
ans = x.abs + y.abs
puts "(x:" + x.to_s + ", y:" + y.to_s + ")" + " manhatten dist:" +  ans.to_s
