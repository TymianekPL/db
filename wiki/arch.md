# Architecture definition

## Scope

This is a persistent relational database engine. It is structured into database instances, tables, columns and rows.

## Structure

### Database

Each database is a separate *file* allocated on the filesystem. The most fundamental allocation unit is a *block*. A block is defined as a contiguous array of (aligned) bytes within the database file.

Databases are defined in a shared metafile guarded by a filesystem lock.

### Block

A block is a fixed-size region in the database (multiples of 4kiB). Each block can only belong to a single table. Each block starts with a common header describing the data, and the rest of the block is fixed-size row data.
```
  block
|--------|
| header | <-- 
|--------|
| data   |
|________|
```

#### Block header

- provenance [table id]: 4 bytes - which table it belongs to
- crc: 4 bytes - checksum of data
- previous block: 4 bytes - index to the previous block
- next block: 4 bytes - index to the next block
- log number: 8 bytes - LSN
- type: 1 byte (enum) - data/index/schema
- reserved: 1 byte
- first free: 2 byte - nearest free record
- last insert: 2 byte - last inserted record
- total allocated: 2 byte - total allocated records (including deleted)
- reserved: 32 bytes - reserved for future use

total size: 64 bytes

note: the first block is always a schema type [with table id = 0], and describes the information_table table, which defines other tables.

### Record

a record is a fixed-size (locally within a table, although it changes with structure operations) region within a block data section defining the contents of a single row in a table.
it starts with a common header, the rest of the contents is defined by the table column definition

#### Common header

- 
