<script setup>
  import {ref} from 'vue'

  const message = ref('');
  const reply = ref('');
  const API_ENDPOINT = import.meta.env.VITE_API_URL

  async function send() {
    const res = await fetch(`${API_ENDPOINT}/api/chat`, {
      method: 'POST',
      headers: {'Content-Type': 'application/json'},
      body: JSON.stringify({message: message.value})
    });
    const data = await res.json();
    reply.value = data.reply;
  }

</script>

<template>
  <input v-model="message"/>
  <button @click="send">Senden</button>
  <p>{{ reply }}</p>
</template>