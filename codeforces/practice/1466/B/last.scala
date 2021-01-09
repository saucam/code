import scala.io.StdIn._

object Main {
  def main(args: Array[String]): Unit = {
    val t = readInt
    (0 until t).foreach { k =>
      val n = readInt
      val v = readLine.split(" ").map(_.toInt)
      var prv = 0
      var ans = 0
      v.foreach { i =>
        if (i < prv) {
         ;
        } else if (i > prv) {
          ans += 1
          prv = i
        } else {
          prv = i + 1
          ans += 1
        }
      }
      println(ans)
    }
  }
}
