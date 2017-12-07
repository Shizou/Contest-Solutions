line = gets.to_s
celeb = {}
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
    line = gets.to_s
end
celeb.each{
    |key, value|
    if value 
        print key
    end
}
