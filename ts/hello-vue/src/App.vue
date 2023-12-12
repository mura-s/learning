<script setup lang="ts">
import { ref } from 'vue'
import OneInfo from './components/OneInfo.vue'

const propsTitle = ref('発生した乱数')
const rand = Math.round(Math.random() * 100)
const propsContent = ref(rand)

setTimeout(() => {
  propsTitle.value = '発生した乱数(変更後)'
}, 1000)
</script>

<template>
  <h1>Props基礎</h1>
  <section>
    <h2>テンプレート変数を利用</h2>
    <OneInfo v-bind:title="propsTitle" v-bind:content="propsContent" />
  </section>
</template>
