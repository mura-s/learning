package sample.breeze

import breeze.linalg.SparseVector
import breeze.numerics.sigmoid

import scala.util.hashing.MurmurHash3

/**
  * Breeze Ex2
  *
  * Spark側の sample.LrHashAndOnehotEnc に対応
  *
  * Sparkでのpredictと同じ結果になることを確認
  */
object BreezeLrHashAndOnehotEnc {

  def main(args: Array[String]) = {
    val indexes = Seq(2,3,9,288,313,468,744)
    val values  = Seq(-2.4050657819329797,2.2314881084095766,-0.26292937391632704,3.8969826320353573,-2.142136001425894,-3.9863367067598188,2.2314881084095766)
    val zipped = indexes zip values

    val w = SparseVector(1010)(zipped: _*)
    val intercept = 0.021452741884392144

    val adId = 2
    val spotId = 5
    val deviceId = "2553999c-40b0-4d24-9a78-2d831fb99735"

    val encAdId = onehotEncode(adId, 5)
    val encSpotId = onehotEncode(spotId, 5)
    val hashingDeviceId = hashingTrick(deviceId, 1000)

    val x = SparseVector.vertcat(encAdId, encSpotId, hashingDeviceId)

    val z = w.dot(x) + intercept
    val prob = sigmoid(z)

    println(prob)
  }

  def onehotEncode(v: Int, numFeatures: Int): SparseVector[Double] = {
    if (v < numFeatures)
      SparseVector(numFeatures)((v, 1.0))
    else
      SparseVector.zeros(numFeatures)
  }

  def hashingTrick(v: String, numFeatures: Int): SparseVector[Double] = {
    def nonNegativeMod(x: Int, mod: Int): Int = {
      val rawMod = x % mod
      rawMod + (if (rawMod < 0) mod else 0)
    }

    val hash = MurmurHash3.stringHash(v)
    val index = nonNegativeMod(hash, numFeatures)

    SparseVector(numFeatures)((index, 1.0))
  }

}
