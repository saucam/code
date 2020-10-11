import scala.io.StdIn._

object Main {
  def main(args: Array[String]): Unit = {
    val n = readInt
    var c = 1
    val arr = new Array[Int](n+1)
    for(i <- 2 to n) {
      if (arr(i) == 0) {
        arr(i) = c
        for (j <- i to n by i) {
          arr(j) = c
        }
        c += 1
      }
    }
    println(arr.tail.tail.mkString(" "))
  }
}
