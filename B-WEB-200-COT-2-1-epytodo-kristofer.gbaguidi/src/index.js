require('dotenv').config();

const express = require('express');
const app = express();
const port = 3000;
const { db }= require('./config/db');
const bcrypt = require('bcryptjs');
const parsing = require('body-parser');
const authroute = require('./routes/auth/auth');
const { TokenExpiredError } = require('jsonwebtoken');
//const userroute = require('./routes/user/user');
//const todosroute = require('./routes/todos/todos');

app.use(express.json());

db.connect(err => {
  if (err)  {
    console.log('aucune connection');
  }
  console.log('connect');
})

app.use('/', authroute);

app.get('/', (req, res) => {
  res.send('Hello World!')
})

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})
