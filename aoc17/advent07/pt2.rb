def rec(name)
    adj_list = $adj[name]
    cur_wt = $wts[name]
    if adj_list.empty?
        return cur_wt 
    end
    sub_tree_wt = 0
    child_vals = {}
    child_tree_vals = {}
    ind_child_wts = {}
    for i in 0...adj_list.size
        child = adj_list[i]
        child_wt = rec(child)
        ind_child_wt = $wts[child]
        sub_tree_wt += child_wt
        child_tree_vals[child]=child_wt
        ind_child_wts[child]=ind_child_wt
        if not child_vals.has_key? child_wt
            child_vals[child_wt] = 1
        else
            child_vals[child_wt] += 1
        end
    end
    if child_vals.size==2
        # you can figure out which tower needs to be changed since inductively
        # the towers of the tower that needs to be changed are all the same
        # so you can just subtract the difference from the tower itself
        print child_tree_vals.to_s + "\n"
        print ind_child_wts.to_s + "\n"
        print "\n"
    end
    return cur_wt + sub_tree_wt
end

line = gets.to_s
celeb = {}
$wts = {}
$adj = {}
while line != ""
    info = line.tr(',', '').tr('(','').tr(')','').split()
    par = info[0]
    wt = info[1]
    children = []
    if info.size > 2
        children = info[3..-1]
    end
    if not celeb.has_key? par
        celeb[par]=true
    end
    for child in children
        celeb[child]=false
    end
    # assign wt for node
    $wts[par]=wt.to_i
    # create adj matrix
    $adj[par] = children
    line = gets.to_s
end
root = ''
celeb.each{
    |key, value|
    if value 
       root = key 
    end
}
rec(root)
