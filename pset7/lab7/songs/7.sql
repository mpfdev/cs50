SELECT AVG(songs.energy) FROM songs
JOIN artists
ON songs.artist_id = artist.id
WHERE artist.name = 'Drake';