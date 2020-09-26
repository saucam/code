import scala.io.StdIn._
import scala.math._

object Main {
  def main(args: Array[String]): Unit = {
    val t = readInt
    (0 until t).foreach { u =>
      val n = readInt
      val a = readLine.split(" ").map(_.toInt)
      val dp = Array.ofDim[Int](n+1, 2)
      dp(1)(0) = a(0)
      dp(1)(1) = a(0)
      if(n >= 2) {
        dp(2)(0) = dp(1)(0) + a(1)
        dp(2)(1) = dp(1)(0)
      }
      for(k <- 3 to n) {
        dp(k)(0) = min(dp(k-1)(1) + a(k - 1), dp(k-2)(1) + a(k-1) + a(k-2))
        dp(k)(1) = min(dp(k-1)(0), dp(k-2)(0))
      }
      println(min(dp(n)(0), dp(n)(1)))
    }
  }
}
