SELECT DISTINCT name FROM people WHERE id IN
    (SELECT person_id FROM directors WHERE movie_id IN
        (SELECT id FROM movies JOIN ratings ON movies.id = ratings.movie_id WHERE ratings.rating >= 9.0));