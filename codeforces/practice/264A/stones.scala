import scala.io.StdIn._

object Main {
  def main(args: Array[String]): Unit = {
    val s = readLine
    val res = new Array[Int](s.size)
    var right = s.size - 1
    var left = 0
    var i = 0
    while(i < s.size) {
      if (s(i) == 'l') {
        res(right) = i + 1
        right -= 1
      } else {
        println(i + 1)  
        left += 1
      }
      i += 1
    }
    var k = left
    while (k<s.size) {
      println(res(k))
      k += 1
    }
  }
}
