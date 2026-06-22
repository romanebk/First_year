const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');
const db = require('../../config/db');
require('dotenv').config();

router.post('/register', async (req, res) => {
  const { email, password, name, firstname } = req.body;

  if (!email || !password || !name || !firstname)
    return res.status(400).json({ msg: 'Bad parameter' });

  try {
    db.query('SELECT * FROM user WHERE email = ?', [email], async (err, results) => {
      if (err) return res.status(500).json({ msg: 'Internal server error' });
      if (results.length > 0) return res.status(400).json({ msg: 'Account already exists' });

      const hashedPassword = await bcrypt.hash(password, 10);

      db.query(
        'INSERT INTO user (email, password, name, firstname) VALUES (?, ?, ?, ?)',
        [email, hashedPassword, name, firstname],
        (err, result) => {
          if (err) return res.status(500).json({ msg: 'Internal server error' });

          const user = { id: result.insertId };
          const token = jwt.sign({ user }, process.env.SECRET, { expiresIn: '1h' });
          return res.status(201).json({ token });
        }
      );
    });
  } catch (err) {
    res.status(500).json({ msg: 'Internal server error' });
  }
});

router.post('/login', (req, res) => {
  const { email, password } = req.body;

  if (!email || !password)
    return res.status(400).json({ msg: 'Bad parameter' });

  db.query('SELECT * FROM user WHERE email = ?', [email], async (err, results) => {
    if (err) return res.status(500).json({ msg: 'Internal server error' });
    if (results.length === 0) return res.status(400).json({ msg: 'Invalid Credentials' });

    const user = results[0];

    const isMatch = await bcrypt.compare(password, user.password);
    if (!isMatch) return res.status(400).json({ msg: 'Invalid Credentials' });

    const token = jwt.sign({ user: { id: user.id } }, process.env.SECRET, { expiresIn: '1h' });
    return res.json({ token });
  });
});

module.exports = router;
