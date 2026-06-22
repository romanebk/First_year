const express = require('express');
const router = express.Router();
const db = require('../../config/db');

router.get('/', (req, res) => {
  const userId = req.user.id;

  db.query('SELECT id, email, password, created_at, firstname, name FROM user WHERE id = ?', [userId], (err, results) => {
    if (err) return res.status(500).json({ msg: 'Internal server error' });

    if (results.length === 0)
      return res.status(404).json({ msg: 'Not found' });

    return res.json(results[0]);
  });
});

router.get('/todos', (req, res) => {
  const userId = req.user.id;

  db.query('SELECT * FROM todo WHERE user_id = ?', [userId], (err, results) => {
    if (err) return res.status(500).json({ msg: 'Internal server error' });

    return res.json(results);
  });
});

router.get('/:idOrEmail', (req, res) => {
  const idOrEmail = req.params.idOrEmail;
  let query = '';
  let value = '';

  if (!isNaN(idOrEmail)) {
    query = 'SELECT id, email, password, created_at, firstname, name FROM user WHERE id = ?';
    value = [parseInt(idOrEmail)];
  } else {
    query = 'SELECT id, email, password, created_at, firstname, name FROM user WHERE email = ?';
    value = [idOrEmail];
  }

  db.query(query, value, (err, results) => {
    if (err) return res.status(500).json({ msg: 'Internal server error' });

    if (results.length === 0)
      return res.status(404).json({ msg: 'Not found' });

    return res.json(results[0]);
  });
});

const bcrypt = require('bcryptjs');

router.put('/:id', async (req, res) => {
  const targetId = parseInt(req.params.id);
  const { email, password, firstname, name } = req.body;

  if (!email || !password || !firstname || !name)
    return res.status(400).json({ msg: 'Bad parameter' });

  if (req.user.id !== targetId)
    return res.status(403).json({ msg: 'Unauthorized' });

  try {
    const hashedPassword = await bcrypt.hash(password, 10);

    db.query(
      `UPDATE user SET email = ?, password = ?, firstname = ?, name = ? WHERE id = ?`,
      [email, hashedPassword, firstname, name, targetId],
      (err, result) => {
        if (err) return res.status(500).json({ msg: 'Internal server error' });

        db.query('SELECT id, email, password, created_at, firstname, name FROM user WHERE id = ?', [targetId], (err, results) => {
          if (err) return res.status(500).json({ msg: 'Internal server error' });

          return res.json(results[0]);
        });
      }
    );
  } catch (err) {
    return res.status(500).json({ msg: 'Internal server error' });
  }
});

router.delete('/:id', (req, res) => {
  const targetId = parseInt(req.params.id);

  if (req.user.id !== targetId)
    return res.status(403).json({ msg: 'Unauthorized' });

  db.query('DELETE FROM user WHERE id = ?', [targetId], (err, result) => {
    if (err) return res.status(500).json({ msg: 'Internal server error' });

    if (result.affectedRows === 0)
      return res.status(404).json({ msg: 'Not found' });

    return res.json({ msg: `Successfully deleted record number: ${targetId}` });
  });
});

module.exports = router;
