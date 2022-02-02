#define BOOST_TEST_DYN_LINK
#include <iostream>
#include <vector>

#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>

#include "matrixIO.hpp"

using namespace std;

using namespace Eigen;

struct MatrixIOFixture {
  MatrixIOFixture()
  {
    expected = MatrixXd(3, 3);
    expected << 0.680375, 0.59688, -0.329554,
        -0.211234, 0.823295, 0.536459,
        0.566198, -0.604897, -0.444451;
  }
  MatrixXd expected;
};

BOOST_FIXTURE_TEST_SUITE(MatrixIOTests, MatrixIOFixture, *boost::unit_test::tolerance(1e-12))

BOOST_AUTO_TEST_CASE(openData)
{
  MatrixXd M;
  M = matrixIO::openData("../data/m3.csv", 3);

  BOOST_TEST(M(0, 0) == expected(0, 0));
  BOOST_TEST(M(0, 1) == expected(0, 1));
  BOOST_TEST(M(0, 2) == expected(0, 2));
  BOOST_TEST(M(1, 0) == expected(1, 0));
  BOOST_TEST(M(1, 1) == expected(1, 1));
  BOOST_TEST(M(1, 2) == expected(1, 2));
  BOOST_TEST(M(2, 0) == expected(2, 0));
  BOOST_TEST(M(2, 1) == expected(2, 1));
  BOOST_TEST(M(2, 2) == expected(2, 2));
}

BOOST_AUTO_TEST_SUITE_END()
