const jwt = const jwt = require('jsonwebtoken');
require('dotenv').config();

function auth(req, res, next) {
    const token = req.header('Authorization');
    if (!token) return res.status(401).json({msg: 'No token'});
    try {
        const decoded = jwt.verify(token, process.env.SECRET);
        req.user = decoded.user;
        next();
    } catch (e) {
          res.status(401).json({msg: 'No token'});
    }
}
module.exports = auth;
