for i in 1..5
    w = gets.chomp.to_i
    encoded_str = gets.chomp

    cols = w
    rows = encoded_str.size()/cols
    
    grid = Array.new(rows) { Array.new(cols) }
    encoded_str_index = 0
    
    for j in 0...cols
        for i in 0...rows
            grid[i][j] = encoded_str[encoded_str_index]
            encoded_str_index += 1
        end
    end

    ans = ''

    for i in 0...rows
        usc_cnt = 0
        for j in 0...cols
            if grid[i][j] == '_'
                usc_cnt += 1
            else
                break
            end
        end
        grid[i] = grid[i][usc_cnt..-1] + ['_']
        for j in 0...grid[i].size()
            grid[i][j] = (grid[i][j] == '_') ? ' ' : grid[i][j]
        end
        ans += grid[i].join
    end

    puts ans

end
