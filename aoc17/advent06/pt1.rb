require 'set'

def block_repr(blocks)
    return blocks.to_s
end

def distribute(blocks, big_elem, big_elem_index)
    blocks[big_elem_index] = 0
    cur_index = (big_elem_index+1) % blocks.size
    blocks_left = big_elem
    while blocks_left > 0
        blocks[cur_index] += 1
        blocks_left -= 1
        cur_index = (cur_index + 1) % blocks.size
    end
end

init_blocks = gets.to_s.split().map(&:to_i)
cur_blocks = init_blocks
seen_so_far = Set.new
distrib_cnt = 0
while not seen_so_far.include? block_repr(cur_blocks)
    seen_so_far << block_repr(cur_blocks)
    big_elem = 0 
    big_elem_index = 0
    for i in 0...cur_blocks.size
        if cur_blocks[i] > big_elem
            big_elem = cur_blocks[i]
            big_elem_index = i
        end
    end
    distribute(cur_blocks, big_elem, big_elem_index)
    distrib_cnt += 1
end
puts distrib_cnt
