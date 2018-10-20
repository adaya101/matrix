#include <iostream>
#include <memory>
#include "matrix.h"

int main () {
  const Matrix<int, 3, 2> m1; // Cretaes 3*2 matrix, with all the default elements equals to 0;
  Matrix<int, 3, 3> m2(4);  // Cretaes 3*3 matrix, with the default elements equals to 4;
  const Matrix<int, 3, 3> m3 = m2; // C-py constructor may take O(MN) and not O(1).

  // min() returns the minimal value in the matrix.
  if (min(m1) < min(m3))
    cout << "Min value of m3 is bigger";

   if (m1.avg() < m3.avg()) // Compares the average of the elements
     cout << "Max value of m3 is bigger";

  m2(0, 0) = 13;
  cout << m2[0][0] << " " << m2[1][0]; // Should print "13 4"

  try {
    cout << m2 + m3  << m3 * m1;  // You can chosse the format of matrix printing;
    cout << m1 * m2;  // This should throw an exception
  } catch (const Matrix<int, 3, 2>::IllegalOperation& e) {
    cout << e.what();
  }

  Matrix<int, 3, 3> m4;
  m4 = m3;
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      m4(i, j) = i+j;
  cout << "m3[1][1] = " << m3[1][1];
  cout << "m4[1][1] = " << m4(1,1);  // m4(1,1) same result as m4[1][1]

  Matrix<int, 3, 3> m5(3);
  m5 = 2 * m4;

  Matrix<int, 3, 3> m6(m4);
    m5 += m4;

  if (m6 != m5)
    cout << "m6 != m5";

  Matrix<Matrix<int, 3, 2>, 4, 4> composite(m1); // Cretaes matrix, where each element is m1;
  cout << composite;

  auto_ptr<Matrix<int, 3, 3>> symetric_matrix(new SymetricMatrix<int, 3>(5)); // SymetricMatrix matrix 3*3 with default element equals to 5;
  (*symetric_matrix)(1, 2) = 8;
  cout << (*symetric_matrix)[1][2]  << " " << (*symetric_matrix)[2][1]; // Should print "8 8"

  return 0;

}
