import scala.io.StdIn._

object Main {
  
  def power(a: Double, n: Int): Double = {
    var ans = 1.0
    var b = a
    var p = n
    while (p > 0) {
      if ( (p & 0x01) != 0) ans = b * ans
      b = b * b
      p = p >> 1;
    }
    ans
  }
  def main(args: Array[String]): Unit = {
    val mn = readLine.split(" ").map(_.toInt)
    val m = mn.head
    val n = mn.last
    val ans = (1 to m).map { k =>
      k * (power((k*1.0)/m, n) - power(((k*1.0) - 1.0)/m, n))
    }.sum
    println(ans)
  }
}
