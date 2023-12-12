<script setup lang="ts">
import { ref } from 'vue'

const name = ref('Test Name')
</script>

<template>
  <h1>Hello, {{ name }}!</h1>
</template>
