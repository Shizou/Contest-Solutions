require 'matrix'

for i in 1..2
    x_1 , y_1 = gets.chomp.split(" ").map(&:to_f)
    x_2 , y_2 = gets.chomp.split(" ").map(&:to_f)
    x_3 , y_3 = gets.chomp.split(" ").map(&:to_f)

    m11 = Matrix[[x_1,y_1,1], 
                 [x_2,y_2,1], 
                 [x_3,y_3,1]]
    m12 = Matrix[[x_1**2+y_1**2, y_1, 1],
                 [x_2**2+y_2**2, y_2, 1], 
                 [x_3**2+y_3**2, y_3, 1]]
    m13 = Matrix[[x_1**2+y_1**2, x_1, 1],
                 [x_2**2+y_2**2, x_2, 1], 
                 [x_3**2+y_3**2, x_3, 1]]
    x = 1/2.0*(m12.determinant/m11.determinant)
    y = -1/2.0*(m13.determinant/m11.determinant)
    puts "#{'%.02f' % x} #{'%.02f' % y}"
end
